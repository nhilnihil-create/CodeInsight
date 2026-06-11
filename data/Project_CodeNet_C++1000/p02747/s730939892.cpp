#include <bits/stdc++.h>
using namespace std;

int main()
{
  string N;
  int count=0;
  cin >> N;
  if(N=="hi") count++;
  if(N=="hihi") count++;
  if(N=="hihihi") count++;
  if(N=="hihihihi") count++;
  if(N=="hihihihihi") count++; 
  
  if(count >=1) cout << "Yes" <<endl;
  else cout<< "No" << endl;
}
/*
  for(int i=0;i<=N;i++){
	 for(int j=0;j<=N;j++){
		int k = N - i - j;
       if(10000*i+5000*j+1000*k==Y && i+j+k<=N){
			A = i,B=j,C=k;            
            }
        }
     }
  
  cout << A << " " << B << " " << C;
}
*/