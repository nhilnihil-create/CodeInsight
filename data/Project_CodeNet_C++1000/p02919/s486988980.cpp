#include<bits/stdc++.h>
using namespace std;
#define mx 200000
int tr[mx*5];
int ar[mx+3];
void seg(int no,int s,int e,int ind){
    if(s==e){
        tr[no] = s;
        return;
    }
    int mid=(s+e)/2;
    if(mid>=ind)
    seg(no*2,s,mid,ind);
    else 
    seg(no*2+1,mid+1,e,ind);
    if(ar[tr[no*2]]>ar[tr[no*2+1]])tr[no] = tr[no*2];
    else tr[no] = tr[no*2+1];
}
int val;
int qu(int no,int s,int e,int st,int en, bool fl){
    if(s>=st&&e<=en){
        if(s==e)return tr[no];
        int mid =(s+e)/2;
        if(fl==0){
            int pos= tr[no*2];
            int pos1=tr[no*2+1];
           // cout<<st<<" "<<en<<" "<<pos<<" "<<pos1<<endl;
            if(ar[pos1]>val)return qu(no*2+ 1,mid+1,e,st,en,fl);
            else return qu(no*2,s,mid,st,en,fl);
        }
        else 
        {
            int pos= tr[no*2];
            int pos1=tr[no*2+1];
           // cout<<s<<" "<<e<<" "<<pos<<" "<<pos1<<" "<<val<<" "<<ar[pos]<<endl;
            if(ar[pos]>val)return qu(no*2,s,mid,st,en,fl);
            else return  qu(no*2+1,mid+1,e,st,en,fl);
        }
    }
    int mid = (s+e)/2;
    if(mid>=en)return qu(no*2,s,mid,st,en,fl);
    else if(mid<st)return qu(no*2+1, mid+1,e,st,en,fl);
    else
    {
        if(fl==0){
            int pos= qu(no*2, s, mid,st,mid,fl);
            int pos1=qu(no*2+1,mid+1,e,mid+1,en,fl);
            if(ar[pos1]>val)return pos1;
            else return pos;
        }
        else 
        {
     
            int pos= qu(no*2, s, mid,st,mid,fl);
            int pos1=qu(no*2+1,mid+1,e,mid+1,en,fl);
                   //cout<<st<<" "<<mid<<" "<<en<<" "<<pos<<" "<<pos1<<endl;
            if(ar[pos]>val)return pos;
            else return pos1;
        }
    }
    
}
#define ll long long 
int main(){

    int tc,n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>ar[i];
    }
       ar[0] = n+1, ar[n+1] = n+1;
    for(int i=0;i<=n+1;i++)seg(1,0,n+1,i);
 
//     seg(1,0,n+1);
//     //val = ar[2];
//    // cout<<(qu(1,0,n+1,3,n+1,1))<<endl;
//     for(int i=1;i<=n;i++){
//         val = ar[i];
        
//     }

    //cout<<qu(1,0,n+1,0,0,0)<<endl;
    ll ans =0;
    for(int i=1;i<=n;i++){
        val = ar[i];
        int fi1,fi2=-1,sc1,sc2=n+2;
        fi1 = qu(1,0,n+1, 0, i-1,0);
        if(fi1>0)fi2=qu(1,0,n+1,0,fi1-1,0);
         sc1 = qu(1,0,n+1, i+1, n+1,1);
        if(sc1 <= n)sc2=qu(1,0,n+1,sc1+1,n+1,1);
       // cout<<i<<" "<<fi2<<" "<<fi1<<" "<<sc1<< " "<<sc2<<endl;
        ll kol = (fi1>0?((fi1-fi2)*(sc1-i)):0) + (sc1<=n?((sc2-sc1)*(i-fi1)):0);
       // cout<<kol<<endl;
        ans+=kol*(ll)val;

    } 
    cout<<ans<<endl;

    return 0;
}