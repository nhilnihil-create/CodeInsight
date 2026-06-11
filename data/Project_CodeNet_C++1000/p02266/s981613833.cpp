#include <bits/stdc++.h>
#include <tuple>

#define REP(i, n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define square(x) (x) * (x)
#define cube(x) (x) * (x) * (x)

const int INF = 1e9;

using namespace std;

stack<tuple<int, int, int> > area;
stack<int> res;
stack<int> downs;

int integrate(int i, int j){
    int value = j-i;
    while(!area.empty() && get<1>(area.top()) >= i && get<2>(area.top()) <= j){
        value += get<0>(area.top());
        area.pop();
    }
    return value;
}

int main() {
    string str;
    int total = 0;
    int temp = 0;
    cin >> str;
    int n = str.length();
    REP(i, n){
        string query = str.substr(i, 1);
        if(query == "\\"){
            downs.push(i);
        } else if(query == "/" && !downs.empty()){
            area.push(make_tuple(integrate(downs.top(), i), downs.top(), i));
            downs.pop();
        }
    }

    while(!area.empty()){
        res.push(get<0>(area.top()));
        total += get<0>(area.top());
        area.pop();
    }
    cout << total << endl << res.size();
    while(!res.empty()){
        cout << " " << res.top();
        res.pop();
    }
    cout << endl;

    return 0;
}