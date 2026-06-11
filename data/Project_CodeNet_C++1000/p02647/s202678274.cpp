#include<bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> lamps(N);
    for(int i=0; i<N; i++){
        cin >> lamps.at(i);
    }

    int k;
    for(k=0; k<K; k++){
        int minIntensity = *min_element(lamps.begin(), lamps.end());
        if(minIntensity == N)break;

        vector<int> next(N+1,0);
        for(int i=0; i<N; i++){
            int intensity = lamps.at(i);

            int l = max(0, i-intensity);
            int r = min(N-1, i+intensity);

            next.at(l)++;
            if(r+1<N)next.at(r+1)--;
        }

        for(int i=1; i<N; i++)next.at(i) += next.at(i-1);

        copy(next.begin(), next.end(), lamps.begin());
    }

    // cout << "k: " << k << endl;
    for(int i=0; i<N; i++){
        if(i==N-1)cout << lamps.at(i) << endl;
        else cout << lamps.at(i) << " ";
    }
}