#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Vec = vector<int>;

bool Isprime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; 
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}

int main() {

    // greenbin 解答中
    
   int n;
   cin>>n;
   vector<string> vec(n);

   for(int i=0;i<n;i++){
       string s;

       cin>>s;

       sort(s.begin(),s.end());
       vec[i]=s;

   }

   sort(vec.begin(),vec.end());
  
  bool x=false;

  Vec conti(0,0);    //　連続した回数の配列

  for(int i=0;i<=n-1;i++){

   if(vec[i]==vec[i+1]){
     
       if(x){
         conti.back()++;
     }
       else{
         conti.emplace_back(1);

         x=true;
     }
     
   }

   else{
        x=false;
     }
  }

  ll ans=0;

  for(int i=0;i<conti.size();i++){

    if(conti[i]%2==0){

      ll p=conti[i]/2;

         p*=conti[i]+1;

         ans+=p;
    }

    else{

       ll p=(conti[i]+1)/2;

         p*=conti[i];

         ans+=p;
    }

    }

  cout<<ans<<endl;

}
 
