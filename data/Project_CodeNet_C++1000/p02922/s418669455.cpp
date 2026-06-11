#include <stdio.h>
#include <iostream>



int main(){
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);//gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    int stripSize;
    std::cin >> stripSize;
    int newEach = stripSize - 1;

    int goal;
    std::cin >> goal;
    goal = goal -1; //you already have one socket

    if (goal < 1){
        std::cout << 0;
    }else{
        std::cout << (goal-1)/newEach +1;
    }
}

