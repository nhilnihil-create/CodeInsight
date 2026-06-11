#include <iostream>
#include <vector>

using namespace std;

int n;
int s;
vector<int> num;

long long memo[102][21];

//i+1項目以降の和がs-sumになる通りの数
long long solve(int i, int sum){
    if(sum < 0 || sum > 20) return 0;
    if(memo[i][sum] != -1)return memo[i][sum];

    if(i==n){
        return (sum == s) ? 1 : 0;
    }
    return memo[i][sum] = solve(i+1,sum+num[i]) + solve(i+1,sum-num[i]);
}

int main(){
    for(int i=0; i < 102*21; i++){
        *(*memo + i) = -1;
    }
    int tmp;
    cin >> n;
    n--;
    for(int i=0;i<n;i++){
        cin >> tmp;
        num.push_back(tmp);
    }
    cin >> s;
    cout << solve(1,num[0]) << endl;
}