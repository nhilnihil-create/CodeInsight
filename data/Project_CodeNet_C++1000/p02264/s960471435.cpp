#include <iostream>
#include <queue>

using namespace std;

struct process{
    string name;
    int time;
    process(const string &name, int time) : name(name), time(time) {}
};

int main(){
    string s;
    queue<process> q;
    int n, t, total = 0;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) {
        string name;
        int time;
        cin >> name >> time;
        q.push(process(name,time));
    }
    while(q.size() > 0){
        process p = q.front();
        q.pop();
        if (p.time <= t){
            cout << p.name << " " << total + p.time << endl;
            total += p.time;
        } else {
            p.time -= t;
            q.push(p);
            total += t;
        }

    }

    return 0;
}