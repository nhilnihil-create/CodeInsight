#include <stdlib.h> 
#include <stdio.h>
#include <iostream>


using namespace std; 

void swap(int &x, int &y) {
    int aux = x;
    x = y;
    y = aux;
} 

int main()
{
    int x,y,z;

    cin>>x;
  	cin>>y;
  	cin>>z;

    swap(x,y);
    swap(x,z);

    cout<<x<<" "<<y<<" "<<z;
}

