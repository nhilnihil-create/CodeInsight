/*ॐॐ*/
/* I have already deleted My old account because somebody stole my code
and i have no idea how. If you are copying this code atleast make it look different.
Change variable names or change some Data structres or anything just make sure MOSS do not
Detect Anything.
Yours Faithfully
Shobhit Yadav */

/* I do not fear this new challenge. Rather like a true warrior I will rise to meet it. 
                                       -Prince Vegeta  */

 /* “Strength is the only thing that matters in this world. Everything else is just a delusion for the weak.” – Vegeta */

#include<bits/stdc++.h>
using namespace std;
#define ll long long 



ll N;
/*ll freq[200005];*/
void solve(){
   /*memset(freq,0,sizeof(freq));*/
   cin>>N;
   double X[N] , Y[N];
   double sum = 0;
   for(ll i = 0 ; i<N ; i++){
     cin>>X[i]>>Y[i];
   }


for(ll i = 0 ; i<N ; i++){
	for(ll j = i+1 ; j<N ; j++){
		sum += (2*sqrt(pow(X[j]-X[i] , 2) + pow(Y[j] - Y[i] , 2)))/N;
	}
}

  cout << fixed << setprecision(10) << sum <<'\n';



   

}



int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  
   solve();

  return 0;
}
