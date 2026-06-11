#include<bits/stdc++.h>
using namespace std;
#define mx (1<<18)
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
   // cout<<val<<endl;
    if(s>=st&&e<=en){
        return tr[no];
    }
    int mid = (s+e)/2;
    if(mid>=en)return qu(no*2,s,mid,st,en,fl);
    else if(mid<st)return qu(no*2+1, mid+1,e,st,en,fl);
    else
    {
        int pos= qu(no*2, s, mid,st,mid,fl);
        int pos1=qu(no*2+1,mid+1,e,mid+1,en,fl);
                //cout<<st<<" "<<mid<<" "<<en<<" "<<pos<<" "<<pos1<<endl;
        if(ar[pos]>ar[pos1])return pos;
        else return pos1;
    }
    
}
#define ll long long 
int main(){
   //cout<<(1<<18)<<endl;
    int n;
    //cin>>n;
    scanf("%d", &n);
    int m= (1<<n);
    set<pair<int,int> > st;
    for(int i=1;i<=m;i++){
        scanf("%d", &ar[i]);
        st.insert(make_pair(ar[i],i));
    }
    sort(ar+1,ar+m+1);
    int a[m+2];
    for(int i=1;i<=m;i++){a[i]=ar[i];  
        seg(1,1,m,i);
     } 
   // reverse(ar+1,ar+m+1);
    int ans[m+2];
    int l =1;
    ans[1]= ar[m];
    ar[m] = -1;
    seg(1,1,m,m);
    int cnt = 0;
    for(int i = 1;i<m;i*=2){
        for(int j=1;j<=i;j++){
            cnt++;
            int x = lower_bound(a+1,a+m+1,ans[j])-a;
            if(x>1){
                int ind = qu(1,1,m,1,x-1,1);
                if(ar[ind]!=-1){
                    ans[++l] = ar[ind];
                    ar[ind] = -1;
                    seg(1,1,m,ind);

                }
                else {
                    cout<<"No"<<endl;
                    return 0;
                }

            }
            else 
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
   // cout<<cnt<<endl;
    cout<<"Yes"<<endl;
    return 0;
}
