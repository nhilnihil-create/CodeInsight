#include <iostream>
using namespace std;

int main(void){
  while(1){
    int stone[50];
    for(int k = 0 ; k < 50 ; k++){stone[k] = 0;}

    int bowl;
    int n, p;  // n：候補者人数，p：小石の総数
    cin >> n;
    cin >> p;

    if(n == 0 && p == 0){return 0;}

    bowl = p;

    bool flg = true;
    int ans;

    for(int i = 0 ; flg ; i = (i+1) % n){

      if(bowl == 0){
        bowl = bowl + stone[i];
        stone[i] = 0;
      }else{
        stone[i]++;
        bowl--;
        if(bowl == 0 && stone[i] == p){ans = i; flg = false;}
      }
    }

    for(int i = 0 ; i < 10000000 ; i++){
        for(int j = 0 ; j < 10000000 ; j++){
            for(int k = 0 ; k < 10000000 ; k++){
                for(int l = 0 ; l < 10000000 ; l++){
                    int K = l + i + j + k;
                }
            }
        }    
    }


    cout << ans << endl;
  }
}

