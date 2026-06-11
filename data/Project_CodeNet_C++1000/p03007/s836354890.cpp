#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> viNum(n);
    for(int i = 0; i < n; i++){
        scanf("%d", &viNum[i]);
    }
    sort(viNum.begin(), viNum.end());
  
    if(viNum[n-1] <= 0){//全負
        int nAns = viNum[n-1];
        for(int i = 0; i < n-1; i++){
            nAns -= viNum[i];
        }
        printf("%d\n", nAns);
        int nTmp = viNum[n-1];
        for(int i = 0; i < n-1; i++){
            printf("%d %d\n", nTmp, viNum[i]);
            nTmp -= viNum[i];
        }
    } else if(viNum[0] >= 0){//全正
        int nAns = -viNum[0];
        for(int i = 0; i < n-1; i++){
            nAns += viNum[i+1];
        }
        printf("%d\n", nAns);
        int nTmp = viNum[0];
        for(int i = 0; i < n-2; i++){
            printf("%d %d\n", nTmp, viNum[i+1]);
            nTmp -= viNum[i+1];
        }
        printf("%d %d\n", viNum[n-1], nTmp);
    } else {//正も負もあり
        int nAns = abs(viNum[0]);
        for(int i = 0; i < n-1; i++){
            nAns += abs(viNum[i+1]);
        }
        printf("%d\n", nAns);
        int k = 0;
        while(k < n-1){
            k++;
            if(viNum[k] > 0){
                k--;
                break;
            }
        }
        int nTmp = viNum[k];
        for(int i = k + 1; i < n-1; i++){
            printf("%d %d\n", nTmp, viNum[i]);
            nTmp -= viNum[i];
        }
        printf("%d %d\n", viNum[n-1], nTmp);
        nTmp = viNum[n-1] - nTmp;
        for(int i = 0; i < k; i++){
            printf("%d %d\n", nTmp, viNum[i]);
            nTmp -= viNum[i];
        }
    }
    
    
    return 0;
}
