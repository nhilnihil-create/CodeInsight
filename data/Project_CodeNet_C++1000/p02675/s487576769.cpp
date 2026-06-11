#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int x;
    cin>>x;
    vector<string> vt(10);
    vt.at(0)="pon";
    vt.at(1)="pon";
    vt.at(2)="hon";
    vt.at(3)="bon";
    vt.at(4)="hon";
    vt.at(5)="hon";
    vt.at(6)="pon";
    vt.at(7)="hon";
    vt.at(8)="pon";
    vt.at(9)="hon";
    cout<<vt[x%10]<<endl;

  return 0;
}
