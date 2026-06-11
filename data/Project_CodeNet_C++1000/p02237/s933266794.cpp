#include <iostream>
using namespace std;

int main(){
    int n, val, link, linknum;
    cin >> n;
    int Graphlinked[n][n];
    for(int i=0; i<n; i++){
        for(int k=0; k<n; k++){
            Graphlinked[i][k] = 0;
        }
        cin >> val >> linknum;
        for(int j=0; j<linknum; j++){
            cin >> link;
            Graphlinked[i][link - 1] = 1;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j) cout << " ";
            cout << Graphlinked[i][j];
        }
        cout << endl;
    }
}
