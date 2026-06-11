#include <iostream>
#include <stdio.h>

using namespace std;

struct Heap{
	int Array[2000000];
	int tamanho;
	
	int pai(int input){
		return (input - 1)/2;
	}
	
	int filhoEsquerdo(int input){
		return (2*input + 1);
	}
	
	int filhoDireito(int input){
		return (2*input + 2);
	}
	
	// Arruma após inserção
	void HeapifyRemover(int arrumar){
		int esquerdo = filhoEsquerdo(arrumar);
		int direito = filhoDireito(arrumar);
		
		int maior = arrumar;
		
		//Vejo quem é maior
		if (esquerdo < tamanho && Array[esquerdo] > Array[arrumar]){
			maior = esquerdo;
		}
		if (direito < tamanho && Array[direito] > Array[maior]){
			maior = direito;
		}
		if (maior != arrumar){
			swap(Array[arrumar], Array[maior]);
			HeapifyRemover(maior);
		}
	}
	
	void HeapifyInserir(int arrumar){
		if (arrumar && Array[pai(arrumar)] < Array[arrumar]){
			swap(Array[pai(arrumar)], Array[arrumar]);
			HeapifyInserir(pai(arrumar));
		}
	}
	
	void inserirHeap(int valor){
		Array[tamanho] = valor;
		tamanho++;
		HeapifyInserir(tamanho-1);
	}
	
	void printaRaiz(){
		printf("%i\n", Array[0]);
	}
	
	int removerRaiz(){
		Array[0] = Array[tamanho-1];
		Array[tamanho-1] = 0;
		tamanho--;
		HeapifyRemover(0);
	}
};

int main(){
	Heap heap;
	string operacao; int valor;
	while(cin >> operacao){
		if (operacao == "insert"){
			cin >> valor;
			heap.inserirHeap(valor);
		} else if (operacao == "extract"){
			heap.printaRaiz();
			heap.removerRaiz();
		} else {
			break;
		}
	}
	return 0;
}

