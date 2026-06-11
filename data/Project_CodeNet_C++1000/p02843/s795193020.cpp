#include <bits/stdc++.h>
#include <vector>
using namespace std;


#define long long ll;


/*

int main() {
	cin >> N >> S;
	for (int i = 0; i < 1000; i++) {
		int c[3] = {i / 100, (i / 10) % 10, i % 10};
		int f = 0;
		for (int j = 0; j < N; j++) {
			if (S[j] == ('0' + c[f])) f++;
			if (f == 3) break;
		}
		if (f == 3) cnt++;
	}
	cout << cnt << endl;
	return 0;
}




int main(){


 long long n;
 cin>>n;

 int enable = 0; long long price=0;

 for(long long i=1;i<=n;i++){


    if( (int)(i*1.08) == n){

        enable = 1;
        price = i;
         break;
        }
 }

  //cout<<price<<" "<<enable<<endl;

 if(enable == true)
    cout<<price<<endl;
 else
    cout<<":("<<endl;

return 0;
}

*/


int main(){

 int n; cin>>n;
  int k = n/100;

  if(n >= 100*k && n<= 105*k)
    cout<<"1"<<endl;
  else cout<<"0"<<endl;

 return 0;
}














