#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

template<typename T>
void cout_vec(vector<T> &vec){
    for(int i=0; i<vec.size(); i++){
        if (i!=0){
            cout << ' ';
        }
        cout << vec[i];
    }
    cout << endl;
}

int main(){
    int N;
    cin >> N;
    vector<int> cnt(N+1,0);
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        cnt[a]++;
    }

    vector<int> memo(N+1,0);
    for(int i=0; i<=N; i++){
        memo[cnt[i]]++;
    }

    //cout_vec(memo);

    for(int i=N; i>0; i--){
        memo[i-1]+=memo[i];
    }

    //cout_vec(memo);

    for(int i=1; i<N; i++){
        memo[i+1]+=memo[i];
    }

    //cout_vec(memo);

    int k=1;
    for(int i=N; i>=0 && k<=N;){
        if(k*i<=memo[i]){
            cout << i << '\n';
            k++;
        }else{
            i--;
        }
    }
}