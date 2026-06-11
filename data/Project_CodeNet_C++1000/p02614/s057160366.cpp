#include <bits/stdc++.h>
using namespace std;
bool count_black(vector<vector<char>> &array,int k){
    int black = 0;
    for(int i=0;i<array.size();i++){
        for(int j=0;j<array.at(0).size();j++){
            if(array.at(i).at(j) == '#') black++;
        }
    }

    return black == k;
}

void show(vector<vector<char>> array){
    for(int i=0;i<array.size();i++){
        for(int j=0;j<array.at(0).size();j++){
            cout << array.at(i).at(j);
        }
        cout << endl;
    }
    cout << endl;
}


int main(){
    int h,w,k;
    cin >> h >> w >> k;
    vector<vector<char>> array(h,vector<char>(w));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> array.at(i).at(j);
        }
    }
    int cnt = 0;
    for(int tmp=0; tmp < (1 << h+w);tmp++){
        bitset<12> b(tmp);
        vector<vector<char>> copy = array;
        for(int i=0;i<h+w;i++){
            if(b.test(i)){
                if(i<h){
                    for(int j=0;j<w;j++){
                        copy.at(i).at(j) = 'r';
                    }
                }else{
                    int yoko_idx = i - h;
                    for(int j=0;j<h;j++){
                        copy.at(j).at(yoko_idx) = 'r';
                    }
                }
            }
            
        }
        //show(copy);
            if(count_black(copy,k)){
                cnt++;
            }
    }
    cout << cnt << endl;
}