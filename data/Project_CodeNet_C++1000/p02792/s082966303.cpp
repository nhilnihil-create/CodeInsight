#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using ll = long long;
using namespace std;

void monmo(){
    
}

int main() {
    int n;
    string s;
    int sum=0;
    vector<vector<int>> v(10,vector<int>(10,0));
    cin>>n;
    for(int i=1;i<=n;i++){
        s=to_string(i);
        int a=s[0]-'0'; //一番左
        int b=s[s.size()-1]-'0';//一番右
        v[a][b]++; //初期値0
    }
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            sum+=v[i][j]*v[j][i];
        }
    }
    cout<<sum;
}
