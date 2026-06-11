        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 1000001;
const int MOD =1000000007;
const int INV2 = (MOD+1)/2;



     signed main(){
 int n,m,t0=1;
 cin>>n;
 queue<int> que;
 int n0=n;
 while(t0<n)t0*=2;
 if(t0==n){
   cout<<"No"<<endl;
   return 0;
 }
 t0/=2;
 bool used[(n>>2)]={};
 m=n;
 cout<<"Yes"<<endl;
 if(n0-t0!=2){
que.push(n);
 while(n%4!=0&&n!=1){
   cout<<n<<' '<<n-1<<endl;
   n--;
   m^=n;
    que.push(n);
 }
 int t=n;
 if(m%4){
   cout<<t<<' '<<m%4<<endl;
   t=(m%4);
   m^=(m%4);
   used[0]=true;
 }
 for(int i=0;m>=(1ll<<i);i++)if(m&(1ll<<i)){
cout<<t<<' '<<(1ll<<i)<<endl;
t=(1ll<<i);
used[t>>2]=true;
 }
 while(!que.empty()){
   cout<<t<<' '<<n0+que.front()<<endl;
  t=n0+que.front();
  que.pop();
 }
 }else{
   cout<<n0<<' '<<n0-1<<endl;
   cout<<2<<' '<<n0+n0<<endl;
     cout<<n0-1<<' '<<n0-2<<endl;
       cout<<1<<' '<<n0-1<<endl;
        cout<<n0+n0-1<<' '<<n0+n0-2<<endl;
       cout<<1<<' '<<n0+n0-2<<endl;
       n-=(n%4);
       used[0]=true;
 }

  if(n/4==0)return 0;
  if(!used[0])cout<<n<<' '<<1<<endl;
   for(int j=1;j<3;j++)cout<<j<<' '<<(1+j)<<endl;
   cout<<3<<' '<<n0+1<<endl;
   for(int j=1;j<3;j++)cout<<n0+j<<' '<<(n0+1+j)<<endl;

 for(int i=1;i*4<n;i++){
   if(!used[i])cout<<n<<' '<<(i<<2)<<endl;
   for(int j=0;j<3;j++)cout<<(i<<2)+j<<' '<<((i<<2)+1+j)<<endl;
   cout<<(i<<2)+3<<' '<<(i<<2)+n0<<endl;
   for(int j=0;j<3;j++)cout<<(i<<2)+n0+j<<' '<<((i<<2)+n0+1+j)<<endl;
 }
 




}


        
