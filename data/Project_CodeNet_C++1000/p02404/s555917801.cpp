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

                for(int i = 1; i <= height; i++){
                        for(int j = 1; j <= width; j++){
                                if(i != 1 && i != height && j != 1 && j != width)
                                        cout << ".";
                                else 
                                        cout << "#";
                        }
                        cout << "\n";
                }
                cout << "\n";
        }

        return 0;
}