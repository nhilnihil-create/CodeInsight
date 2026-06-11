#include <bits/stdc++.h>
using namespace std;
int main() {
    
    long long int n,m;
    cin >> n >> m;
    int used[n];
    int data[n];
    for(int i=0;i<n;i++) used[i]=0;
    //used[0] = 1;

    for(int i=0;i<n;i++){
        cin >> data[i];
    }


    int t=1;
    int p=0;
    while(true){
        if(used[p]) break;
        used[p] = t;
        p = data[p]-1;
        t++;
    }

    //cout << used[p] << " " << t << endl;

    /*for(int i=0;i<n;i++){
        cout << used[i] << " ";
    }
    cout << endl;
    */
    //cout << m << endl;
    int loop = (m-used[p]+1) % (t-used[p]);

    for(int i=0;i<loop;i++) {
        p = data[p]-1;
    }

    if(m < used[p]) {
        p=0;
        for(int i=0;i<m;i++) {
            p = data[p]-1;
        }
        cout << p+1 << endl;
        return 0;
    }

    cout << p+1 << endl;
} 