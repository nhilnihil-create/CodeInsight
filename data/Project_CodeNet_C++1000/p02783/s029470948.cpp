#include <stdio.h>

int main(){

    int darahMusuh;
    int attackServal;
    int jumlahSerangan;
    
    scanf("%d %d", &darahMusuh, &attackServal);
    jumlahSerangan=darahMusuh/attackServal;
    darahMusuh%attackServal!=0?jumlahSerangan+=1:jumlahSerangan;
    printf("%d", jumlahSerangan);


    return 0;
}