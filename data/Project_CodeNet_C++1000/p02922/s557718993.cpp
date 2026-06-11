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
    int A,B;
    cin >> A >> B;
    int sum=1;
    int c=0;
    while(sum<B){
        sum+=A-1;
        c++;
    }
    cout << c << endl;
    return 0;

}

