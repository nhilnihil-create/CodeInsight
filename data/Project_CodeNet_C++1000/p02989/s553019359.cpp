#include <bits/stdc++.h>
using namespace std;
#define MAX pow(10,18)
typedef long long ll;

int main(){
  
   int N,harf;
   cin >> N;
   harf = N/2;
   int data[N];
   for(int i=0;i<N;i++) cin >> data[i];
   sort(data,data+N);
 
   cout << data[harf] - data[harf-1] << endl;
}