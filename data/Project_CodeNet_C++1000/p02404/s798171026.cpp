#include<iostream>
#include<stdio.h>
 using namespace std;
int main()
{
    int h, w;
    int i, j;
    cin >> h;
    cin >> w;
    while (h != 0 || w != 0){
        for (i = 0; i < h; i++){
        	if(i+1!=1&&i+1!=h){
            	for (j = 0; j < w; j++){
	                if(j+1==1||j+1==w)cout << "#";
	                else cout << ".";
	            }
        	}
        	if(i+1==1||i+1==h){
        		for (j = 0; j < w; j++)cout << "#";
        	}
            cout << "\n";
        }
        cout << "\n";
        cin >> h;
        cin >> w;
    }
    return 0;
}