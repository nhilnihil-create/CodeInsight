#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
#include<map>
#include<iostream>
#include<math.h>
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;


int main(){
   int X, Y, Z;
   cin >> X >> Y >> Z;
   int tmp;
   tmp = Y;
   Y = X;
   X = Z;
   Z = tmp;
   cout << X << " " << Y  << " " << Z;
}