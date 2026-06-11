#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<pair<int,int>> tasks; //pairを配列にして用意する.
    cin >> n;

    for(int i = 0; i < n;i++){
        int x,y;
        cin >> x >> y;
        tasks.emplace_back(y,x); //入力 push_backよりもこっちを使う方がいい
    }

    sort(tasks.begin(),tasks.end()); //sort
    int sum = 0;
    bool out = true;
    for(int i = 0; i < n; i++){
        sum += tasks[i].second;
        if(sum > tasks[i].first){
            out = false;
            break;
        }
    }
    if(out){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}