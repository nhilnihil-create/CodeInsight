#include<iostream>
#define MAX_NUM 100000

bool test(int p,int n,int k,int w[]){
    int track = p;
    int i = 0,j = 0;
    while(j != n){
        if(track >= w[j]){
            track -= w[j];
            j++;
        }else{
            track = p;
            i++;
            if(i == k) return false;
        }
    }
    return true;
}

int main(){
    int n,k,max=0;
    int w[MAX_NUM] = {};
    std::cin >> n >> k;
    for(int i=0;i<n;i++){
        std::cin >> w[i];
        if(max<w[i]){
            max = w[i];
        }
    }
    //std::cout << max << "から" << "調べます\n";
    int left=max;
    if(test(left,n,k,w)){
        std::cout << left << '\n';
        return 0;
    }else{
        //std::cout << max << "でテスト:失敗\n";
    }
    int t;
    int right = max*n;
    int min;
    while(left <= right){
        t = (left+right)/2;
        //std::cout << left << ' ' << right << ' ' << t << "でテスト:";
        if(test(t,n,k,w)){
            //std::cout << "成功-->" << t << '\n';
            min = t;
            right = t-1;
        }else{
            //std::cout << "失敗\n";
            left = t+1;
        }
    }
    std::cout << min << '\n';
    
    return 0;
}

