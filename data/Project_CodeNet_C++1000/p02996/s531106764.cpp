#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    int n;  cin >> n;
    vector<pair<int, int> >task;
    rep(i, n){
        int a, b;
        cin >> a >> b;
        task.emplace_back(b, a);
    }
    sort(task.begin(), task.end());
    int sum = 0;
    bool flag = true;
    for(auto v :task){
        sum += v.second;
        if(sum > v.first){
            flag = false;
            break;
        }
    }
    cout << (flag?"Yes":"No") << endl;
}
