#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

        int height,width;

        while(true){
                cin >> height >> width;
                if(height == 0 && width == 0)break;

                for(int i = 0; i < height; i++){
                        for(int j = 0; j < width; j++){
                                cout << "#";
                        }
                        cout << "\n";
                }
                cout << "\n";
        }

        return 0;
}