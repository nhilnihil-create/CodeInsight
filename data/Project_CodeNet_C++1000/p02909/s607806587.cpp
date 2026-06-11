#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
#define INF 1000000100
#define rep(i,n) for (int i=0;i<n;i++)

int main(){
    string S;
    cin >> S;
    if(S=="Sunny") cout << "Cloudy";
    if(S=="Cloudy") cout << "Rainy";
    if(S=="Rainy") cout << "Sunny";
    return 0;
}

