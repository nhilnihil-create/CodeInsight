#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H,W;
    char S[2100][2100];

    cin>>H>>W;
    
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>S[i][j];
        }
    }

    vector<vector<int> > right(H,vector<int>(W,0));
    vector<vector<int> > left(H,vector<int>(W,0));
    vector<vector<int> > under(H,vector<int>(W,0));
    vector<vector<int> > up(H,vector<int>(W,0));

    for(int i=0; i<H; i++){
        int cnt = 0;
        for(int j=0; j<W; j++){
            if(S[i][j] == '#') cnt = 0;
            else cnt++;
            left[i][j] = cnt;
        }
    }

    for(int i=0; i<H; i++){
        int cnt = 0;
        for(int j=W-1; j>=0; j--){
            if(S[i][j] == '#') cnt = 0;
            else cnt++;
            right[i][j] = cnt;
        }
    }

    for(int j=0; j<W; j++){
        int cnt = 0;
        for(int i=0; i<H; i++){
            if(S[i][j] == '#') cnt = 0;
            else cnt++;
            up[i][j] = cnt;
        }
    }

    for(int j=0; j<W; j++){
        int cnt = 0;
        for(int i=H-1; i>=0; i--){
            if(S[i][j] == '#') cnt = 0;
            else cnt++;
            under[i][j] = cnt;
        }
    }

    int ans = 0;

    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            ans = max(ans,(right[i][j] + left[i][j] + under[i][j] + up[i][j] - 3));
        }
    }

    cout<<ans<<endl;
}