#include <bits/stdc++.h>
using namespace std;
 
#define clr(i, j)     memset(i, j, sizeof(i))
#define pb            push_back
 #define PI acos(-1)
 #define MOD ((int)1e9+7)
typedef long long     ll;
 
//-*-*-*-*-*-*-*-*-
 
 

 
const int N=2e5+100;
ll visited[100005];
//ll a[200000];
 

#define lop(i,n) for(int i=0;i<n;++i)
//ll n,m,mod;

int dx[4] = {1 , 0 , 0 , -1} ;
int dy[4] = {0 , 1 , -1 , 0} ;

const int MAX = 2e5 + 10 ;
void finis(){cout<<-1;}


string arr[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
ll h,w,n,m,k;
ll x,y,a,b,c;
int main()
{  ios::sync_with_stdio(0);
cin.tie(0);

cin>>x>>y>>a>>b>>c;
ll r[a];ll g[b];ll l[c];
for(int i=0;i<a;i++){
    cin>>r[i];
}for(int i=0;i<b;i++){
    cin>>g[i];
}for(int i=0;i<c;i++){
    cin>>l[i];
}
sort(r,r+a);sort(g,g+b);sort(l,l+c);//reverse(r,r+a);reverse(g,g+b);reverse(l,l+c);
ll  p,p1,p2;
p=a-x;
p1=b-y;
p2=c-1;/*
2 2 2 2 2
6 8
1 9
1 2*/
/*
1 2 2 2 1
2 4
3 5
3
*/
while(p<a&&p1<b&&p2>=0){
    ll mon=min(r[p],g[p1]);if(l[p2]>mon){
        if(mon==r[p]){
            r[p]=l[p2];
            p++;p2--;
        }else if(mon==g[p1]){
            g[p1]=l[p2];
            p1++;p2--;
        }
    }else {break;}
    
}while(p<a&&p2>=0){
    ll mon=r[p];if(l[p2]>mon){
       
            r[p]=l[p2];
            p++;p2--;
        
    }else {break;}
    
}while(p1<b&&p2>=0){
    ll mon=g[p1];if(l[p2]>mon){
       
            g[p1]=l[p2];
            p1++;c--;
        
    }else {break;}
    
}
ll ans=0;
for(int i=a-x;i<a;i++){
   // cout<<r[i]<<" ";
   ans+=r[i];
}cout<<endl;for(int i=b-y;i<b;i++){
 // cout<<g[i]<<" ";
 ans+=g[i];
}

cout<<ans;

    
}
