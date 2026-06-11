#include<bits/stdc++.h>

using namespace std;

int main(){
  cout << fixed << setprecision(12);
  int n;
  double x[100],y[100];
  double D1=0,D2=0,D3=0,Dm=0;

  cin >> n;

  for(int i=0;i < n;i++)
    {
      cin >> x[i];
    }
  for(int i=0;i < n;i++)
    {
      cin >> y[i];
    }

  for(int j=0;j < n;j++)
    {
      D1 += abs(x[j]-y[j]);
    }
  for(int j=0;j < n;j++)
    {
      D2 += pow((x[j]-y[j]),2);
    }
  for(int j=0;j < n;j++)
    {
      D3 += pow(abs(x[j]-y[j]),3);
    }
  Dm =0;
  for(int j=0;j < n;j++)
    {
      Dm = max(Dm,abs(x[j]-y[j]));
    }

  cout << D1 << endl;
  cout << sqrt(D2) << endl;
  cout << pow(D3,1.0/3) << endl;
  cout << Dm << endl;

  return 0;
}

