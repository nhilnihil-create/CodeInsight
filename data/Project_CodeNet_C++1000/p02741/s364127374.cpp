#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
const int INT_INF = 1001001001;
//stoi(s) : string→int stoll(s) :string→longlong  int→string to_string(i)
const double PI = acos(-1.0);
//小数点の表し方 cout << fixed << setprecision(5);
int x[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main(){
    int n;
    cin >> n;
    cout <<x[n-1]<< endl; 
}