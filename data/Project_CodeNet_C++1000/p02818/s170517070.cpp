#include <bits/stdc++.h>
#define INF 1e7
#define dsec 86400

using namespace std;
typedef long long int ll;
typedef tuple<int,int,int> tii;
typedef tuple<long long int,long long int,long long int> tll;
typedef tuple<double,double,double> tdd;



int main()
{
   ll A,B,K; cin >> A >> B >> K;
   if(A <= K)
   {
       B -= K-A;
       if(B < 0) B = 0;
       A = 0;
       cout << A << " " << B << endl;
   }
   else
   {
       cout << A - K << " " << B << endl;
   }
}