#include <stdio.h>
int main(){
    int row;
    int column;
    int box;
    int count = 0;
    scanf("%d %d %d", &row, &column, &box);
    int temp;//menyimpan nilai row atau column utk sementara
    if(row > column){
        temp = row;
    }
    else// jika baris = kolom,  juga berlaku
    {
        temp = column;
    }
    for(int i = 0; i < box; i = i + temp){
        count++;
    }
    printf("%d\n", count);
    return 0;
}