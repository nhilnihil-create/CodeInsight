
#include<bits/stdc++.h>

int main(){
    using namespace std;
    unsigned long M;
    cin >> M;
    unsigned long dig{~0UL}, sm{~0UL};
    for(unsigned long i{0}, d, c; i < M; ++i){
        cin >> d >> c;
        dig += c;
        sm += d * c;
    }
    cout << dig + sm / 9 << endl;
    return 0;
}