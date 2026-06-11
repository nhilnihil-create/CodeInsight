#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){


  map<string,int> A;
  A["SUN"]=0;
  A["MON"]=1;
  A["TUE"]=2;
  A["WED"]=3;
  A["THU"]=4;
  A["FRI"]=5;
  A["SAT"]=6;




   string S;
   cin >> S;
   cout << 7-A[S];





	return 0;

}

