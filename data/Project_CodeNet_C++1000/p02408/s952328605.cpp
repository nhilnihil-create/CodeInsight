#include <iostream>
#include <vector>
using namespace std;

int conv(char suit){
    switch(suit){
    case 'S': return 0;
    case 'H': return 1;
    case 'C': return 2;
    case 'D': return 3;
    }
    return -1;
}

char conv(int suit){
    switch(suit){
    case 0: return 'S';
    case 1: return 'H';
    case 2: return 'C';
    case 3: return 'D';
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    vector<vector<bool> > card(4, vector<bool>(14, false));
    for(int i=0; i<n; i++){
        char suit;
        int rank;
        cin >> suit >> rank;
        card[conv(suit)][rank] = true;
    }
    for(int i=0; i<4; i++){
        for(int j=1; j<=13; j++){
            if(!card[i][j]){
                cout << conv(i) << " " << j << endl;
            }
        }
    }
    return 0;
}
