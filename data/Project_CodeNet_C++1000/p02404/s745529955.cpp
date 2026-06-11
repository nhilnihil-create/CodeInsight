#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(void){
    int height,width;
    vector<int> vec_height,vec_width;
    cin >> height >> width;
    vec_height.push_back(height);
    vec_width.push_back(width);

    for(int i = 0;height + width;i++){
        cin >> height >> width;
        vec_height.push_back(height);
        vec_width.push_back(width);
    }
    for(int i = 0;vec_height[i] + vec_width[i];i++){
        for (int j=0;j < vec_height[i];j++){
           for(int k=0;k < vec_width[i];k++){
               if(j == 0 || j == vec_height[i] -1 || k==0 || k == vec_width[i]-1)
                   printf("#");
               else
                  printf(".");
           }
        printf("\n");
        }
        printf("\n");
    }
}
