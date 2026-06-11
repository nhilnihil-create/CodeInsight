#include <bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    vector<long long> L;
    long long tmp;
    int count = 0;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        L.push_back(tmp);
    }

    vector<long long> tL;
    for(int i=0; i<(N-2); i++){
        tL.push_back(L[i]);
        for(int j=i; j<(N-1); j++){
            tL.push_back(L[j]);
            for(int k=j; k<N; k++){
                tL.push_back(L[k]);
                if( L[i]!=L[j] && L[i]!=L[k] && L[j]!=L[k]){
                    int max = max_element(tL.begin(),tL.end()) - tL.begin();
                    int maxElement = *max_element(tL.begin(), tL.end());
                    if( (tL[0]+tL[1]+tL[2]) > (maxElement*2) ){
                        count ++;
                    }
                }
                tL.pop_back();
            }
            tL.pop_back();
        }
        tL.pop_back();
    }

    cout << count << endl;

    return 0;
}
