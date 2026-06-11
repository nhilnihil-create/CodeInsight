#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, M, p[100002], box[100002] = {0},
     cntAC = 0, cntWA[100002] = {0};
    string S[100002];

    cin >> N >> M;
    for(int i = 0; i < M; i ++){
        cin >> p[i] >> S[i];
        if(box[p[i]] == 0 && S[i] == "WA"){
            cntWA[p[i]] ++;
        }
        if(box[p[i]] == 0 && S[i] == "AC"){
            box[p[i]] = 1;
            cntAC ++;
        }
    }

    for(int j = 1; j <= N; j ++){
        if(box[j] == 1)cntWA[0] += cntWA[j];
    }
    
    cout << cntAC << " " << cntWA[0] << endl;

    return 0;
}