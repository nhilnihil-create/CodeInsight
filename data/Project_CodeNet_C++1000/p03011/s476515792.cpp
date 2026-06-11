#include<bits/stdc++.h>

using namespace std;

#define endl '\n'
#define tab " "
#define lli long long int


void read(){
    int d;
    vector<int> D;

    for(int i = 0; i < 3; ++i){
        cin >> d;
        D.push_back(d);
    }

    sort(D.begin(), D.end());

    cout << D[0]+D[1] << endl;
}

int main(void){
    read();
    return 0;
}