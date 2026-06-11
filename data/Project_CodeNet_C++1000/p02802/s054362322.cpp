#include <iostream>
#include <string>
using namespace std;
typedef long long ll;


int main(){
    int n,m,pi;
    cin >> n >> m;
    int correct = 0, penalty = 0;
    int done[n] = {};
    string si;
    for (int i=0; i<m;i++){
        cin >> pi >> si;
        if ((si == "AC") && (done[pi-1] != -1)) {
            penalty += done[pi-1];
            done[pi-1] = -1;
            correct++;
        } else if ((si == "WA") && done[pi-1] != -1) {
            done[pi-1]++;
        } 
    }
    cout << correct << " " << penalty << endl;
}