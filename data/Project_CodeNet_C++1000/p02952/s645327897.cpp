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

bool C(int i){
    int keta=0;
    while(i!=0){
        i/=10;
        keta++;
    }
    if(keta%2==1) return true;
    else return false;
}

int main(){
    int N;
    cin >> N;
    int sum=0;
    for(int i=1;i<=N;i++){
        if(C(i)) sum+=1;
    }
    cout << sum << endl;
    return 0;
}