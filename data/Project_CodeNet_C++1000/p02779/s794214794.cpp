#include<bits/stdc++.h>

using namespace std;



int main(){


 
 ios_base::sync_with_stdio(NULL); 
 cin.tie(0);
  #ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
  freopen ("outt.txt", "w", stdout);
#endif

  

int n;
cin>>n;
map<long long , int  > mp ;

for(int i=0;i<n;i++){
  long long a;
  cin>>a;
  mp[a]+=1;

}

for(map<long long  , int > :: iterator it = mp.begin();it!= mp.end();it++){
  if(it->second >= 2){
    cout<<"NO\n";
    return 0;
  }
}

cout<<"YES\n";


}