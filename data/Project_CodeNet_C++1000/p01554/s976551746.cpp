#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n,m,state=0;//??????
    bool flag;
    cin >> n;
    vector<string> u(n);
    for(int j = 0; j<n; j++) {
        cin >> u[j];
    }
    cin >> m;
    vector<string> t(m);
    for(int i = 0; i<m; i++) {
        cin >> t[i];
    }
    for(int i = 0; i<m; i++) {
        flag = false;
        for(int j = 0; j<n; j++) {
            if (u[j] == t[i]) flag = true;
        }
        if (flag == true) {
            if (state == 0) {
                cout << "Opened by " << t[i] << endl;
                state = 1;
            } else {
                cout << "Closed by " << t[i] << endl;
                state = 0;
            }
        } else {
            cout << "Unknown " << t[i] << endl;
        }
    }
        return 0;
}