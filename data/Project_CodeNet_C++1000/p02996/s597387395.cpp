#include<bits/stdc++.h>
using namespace std;
using P = pair<int, int>;
#define ALL(x) (x).begin(), (x).end()

int N, i, j;
vector<P> task;
bool unable = false;

int main(){
    cin >> N;
    task.resize(N);
    for(int i = 0; i < N; i++) cin >> task[i].second >> task[i].first;

    sort(ALL(task)); //締め切り早い順にソート
    i = 0;
    int deadline;
    int day = 0;
    while(i < N){
        deadline = task[i].first;
        while(i < N && task[i].first == deadline) day += task[i++].second;
        if(day > deadline){ unable = true; break; }
    }

    if(unable) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
    
