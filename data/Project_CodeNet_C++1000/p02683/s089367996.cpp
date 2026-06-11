#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<long long, vector<long long>>> outcome;

void go(vector<vector<long long>> information, long long x, long long m, long long n, long long index, vector<long long> information_acc, long long price_acc){
    if (index == n){
        auto success_flag = true;
        for (long long val : information_acc){
            if (val < x){
                success_flag = false;
                break;
            }
        }
        if (success_flag){
            outcome.push_back(make_pair(price_acc, information_acc));
        }
        return;
    } else {
        go(information, x, m, n, index+1, information_acc, price_acc);
        for (long long i=0;i<m;i++){
            information_acc[i] += information[index][i+1];
        }
        go(information, x, m, n, index+1, information_acc, price_acc + information[index][0]);
    }
}

int main(){
    long long n, m, x;
    cin>>n>>m>>x;
    vector<vector<long long>> information(n);
    for (long long i=0;i<n;i++){
        vector<long long> book(m+1);
        for (long long j=0;j<m+1;j++){
            cin >> book[j];
        }
        information[i] = book;
    }
    vector<long long> information_acc(m);for(long long i=0;i<m;i++){information_acc[i]=0;};

    go(information, x, m, n, 0, information_acc, 0);
    if (outcome.size() == 0){
        cout << -1 << endl;
    } else {
        sort(outcome.begin(), outcome.end());
        cout << outcome[0].first << endl;
    }
    

    return 0;
}