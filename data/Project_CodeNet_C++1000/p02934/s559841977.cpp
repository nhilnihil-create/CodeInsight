#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int  main(){
int N;
  cin>>N;
vector<double>a(N);
for(int i=0;i<N; i++){
    cin>>a.at(i);
}
double answer=0.00000;
for(int i=0; i<N; i++){
  double k=1/a.at(i);
    answer+=k;
}
cout<< 1/answer<<endl;
}

