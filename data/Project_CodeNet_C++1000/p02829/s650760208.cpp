/*à¥à¥*/
/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different.
Change variable names or change some Data structres or anything just make sure MOSS do not
Detect Anything.
Yours Faithfully
Shobhit Yadav */

/* I do not fear this new challenge. Rather like a true warrior I will rise to meet it. 
                                       -Prince Vegeta  */

 /* â€œStrength is the only thing that matters in this world. Everything else is just a delusion for the weak.â€ â€“ Vegeta */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 



ll A,B;
/*ll freq[200005];*/
void solve(){
   /*memset(freq,0,sizeof(freq));*/
  cin>>A>>B;
  set<ll> num;
  num.insert(1) ; num.insert(2) ; num.insert(3);

  num.erase(A); num.erase(B);
  cout<<*num.begin()<<'\n';
}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
   solve();

  return 0;
}