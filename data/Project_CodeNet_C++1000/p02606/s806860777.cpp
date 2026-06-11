#include <stdio.h>

int main(){
    int num1, num2, angkaAwal;
    int angka,jumlah = 0;
   
    scanf("%d %d %d", &num1, &num2, &angkaAwal);
    angka = angkaAwal;  
    for(int a = num1; a <= 100; a++){
    if(angka >= num1 && angka <= num2){
            jumlah++;  
        } 
    angka += angkaAwal;
    }
printf("%d\n", jumlah);

    return 0;
}