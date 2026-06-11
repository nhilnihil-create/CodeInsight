#include<bits/stdc++.h>
using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(NULL);
#define deb(x,y) cerr << x << " " << y << "\n"

int main() {
    int problems,submissions;
    cin >> problems >> submissions;
    int correct = 0, penalty = 0;
    vector<bool> ac(problems,false);
    vector<int> wa(problems,0);
    while(submissions--) {
        int problem;
        string verdict;
        cin >> problem >> verdict;
        if(verdict == "AC") {
            if(!ac[problem]) {
                penalty += wa[problem];
                ac[problem] = true;
                correct ++;
            }    
        }
        else {
            wa[problem]++;
        }
    }
    cout << correct << " " << penalty;
}