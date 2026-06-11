#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> H, W;
    for(;;){
        int h, w;
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        H.push_back(h);
        W.push_back(w);
    }
    
    for(int i = 0; i < H.size(); i++){
        for(int h = 0; h < H.at(i); h++){
            for(int w = 0; w < W.at(i); w++){
                if(h % 2 == 0){
                    if(w % 2 == 0) cout << "#";
                    else cout << ".";
                }else{
                    if(w % 2 == 0) cout << ".";
                    else cout << "#";
                }
            }
            cout << endl;
        }
        cout << endl;
    }

}
