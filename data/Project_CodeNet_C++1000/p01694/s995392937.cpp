#include <bits/stdc++.h>
using namespace std;

int solve() {
    int N;
    int prev=0;
    int left_pos = 0;
    int right_pos = 0;
    int counter = 0;
    cin >> N;
    if(N==0) return 0;
    for(int i=0; i<N; i++) {
        string command;
        cin >> command;
        if(command=="lu") {
            left_pos=1;
        } else if(command=="ru") {
            right_pos=1;
        } else if(command=="ld") {
            left_pos=0;
        } else if(command=="rd") {
            right_pos=0;
        }

        if(right_pos==1&&left_pos==1 &&prev==0) {++counter; prev=1;}
        if(right_pos==0&&left_pos==0 &&prev==1) {++counter; prev=0;}
    }
    cout << counter << endl;
    return 1;
}

int main() { while(solve()){}}

