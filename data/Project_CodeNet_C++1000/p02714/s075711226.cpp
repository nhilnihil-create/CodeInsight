#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define ll long long 
/*void setIO(string name = "") { 
    if(sz(name)){
        freopen((name+".in").c_str(), "r", stdin); // see Input & Output
        freopen((name+".out").c_str(), "w", stdout);
    }
}
*/

void fast(){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
}

int main() {
   fast();
   int n;
   cin>>n;
   string s;
   cin>>s;
   long long int ans=0;
   
   long long int f=0;
   long long int g=0;
   long long int h=0;
   for(int i=0;i<n-2;i++){
    for(int k=i+2;k<n;k++){
      int j=(i+k)/2;
      if(s[i]!=s[j] && s[j]!=s[k] && s[k]!=s[i] && j!=i && j!=k && i!=k && (i+k)%2==0){
        ans++;
      }
    }
   }
   for(int i=0;i<n;i++){
      if(s[i]=='R'){
         f++;
      }else if(s[i]=='G'){
         g++;
      }else{
        h++;
      }
   }
 
   cout<<f*g*h-ans<<endl;





   










}