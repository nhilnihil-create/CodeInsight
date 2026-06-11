#include<bits/stdc++.h>
 
using namespace std;
 
int h,v,k;
int row[10],column[10];
char matrix[10][10];
 
int main(){
 
    cin>>h>>v>>k;
    for(int i=0;i<h;i++)
        cin >> matrix[i];
    int uk=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<v;j++){
            if(matrix[i][j]=='#'){
                row[i]++;
                column[j]++;
            }
        }
    }
    int rj=0;
    for(int row_mask=0;row_mask<(1<<h);row_mask++){
        for(int column_mask=0;column_mask<(1<<v);column_mask++){
            int zbr=0;
            for(int i=0;i<h;i++){
                for(int j=0;j<v;j++){
                    if(matrix[i][j]=='#' && (row_mask&(1<<i))==0 && (column_mask&(1<<j))==0)
                        zbr++;
                }
            }
            if(zbr==k)
                rj++;
        }
    }
    cout <<rj<<endl;
 
}
 