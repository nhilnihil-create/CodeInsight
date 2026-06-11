#include <iostream>
#include <string>

using namespace std;

string exchange(string c, int i, int j){
    string temp;
    temp = c[i];
    c[i] = c[j];
    c[j] = temp[0];

    return c;
}

string change(string c, int i){

    if(c[i] == 'W'){c[i] = 'R';}
    else{c[i] = 'W';}

    return c;
}

int judge(string c, int N){
    int t = 0;
    int has_R = 0;
    int area_R = 0;
    
    for(int i = 0; i < N; i++){ //count a number of 'R'
        if(c[i] == 'R'){
            has_R++;
        }
    }


    for (int i = has_R; i < N; i++){

        if(c[i] == 'R'){
            for(int j = area_R; j < has_R; j++){
                if(c[j] == 'W'){
                    c = exchange(c, j, i);
                    t++;
                    area_R = j;

                    break;
                }
            }
        }
        has_R = i;
    }


    return t;
}



int main(void){
    int N;
    string c;

    cin >> N;
    cin >> c;

    int ans;

    ans = judge(c, N);
    cout << ans;
    return 0;
}