        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;


     signed main(){
         cout << std::fixed << std::setprecision(15);
int n,k,c;
cin>>n>>k>>c;
string s;
cin>>s;
if(n==1){
     cout<<1<<endl;
     return 0;
}
int p=0;
int t[n]={},t2[n]={};
while(p<n){
     while(p<n&&s[p]=='x')p++;
     if(p<n){
          t[p]=1;
          p+=c+1;
     }
}
p=n-1;
while(p>=0){
     while(p>=0&&s[p]=='x')p--;
     if(p>=0){
          t2[p]=1;
          p-=c+1;
     }
}
for(int i=1;i<n;i++)t[i]+=t[i-1];
for(int i=n-2;i>=0;i--)t2[i]+=t2[i+1];
if(t2[1]<k)cout<<1<<endl;
for(int i=1;i<n-1;i++)if(t2[i+1]+t[i-1]<k)cout<<i+1<<endl;
if(t[n-2]<k)cout<<n<<endl;
     }

 


 






    





      

        
