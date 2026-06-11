#include <bits/stdc++.h>
using namespace std;

bool is_integer( double x ){
  return floor(x)==x;
}

double Distance(int *p_1,int *p_2,int D){
    
    double sum = 0;
    
    for(int i=0;i<D;i++){
        int r,l;
        l = *(p_1 + i);
        r = *(p_2 + i);
        sum += pow((r-l),2);
    }
    
    return sqrt(sum);
}

int main(void){
    
    int N,D,ans = 0;
    cin >> N >> D;

    int data[N][D];

    for(int i=0;i<N;i++){
        for(int j=0;j<D;j++){
            cin >> data[i][j];
        }
    }
    
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(is_integer(Distance(&data[i][0],&data[j][0],D))) ans++;
        }
    }
    
    cout << ans << endl;
}